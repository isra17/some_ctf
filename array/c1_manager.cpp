class C1 { // Int array manager
  int  is_init;
  int  data[0x100]; // 0x8
  int**items;         // 0x808
  int  size;        // 0x810
  int* print;      // 0x818
  int* vt20;        // 0x820

  int is_init() {
    return is_init;
  }

  C1(){
    this->is_init = 1;
    this->a = this->data;
    this->print = print;
    this->vt20 = c1_vt20;
    this->size = 0;
    memset(this+8, 0, 0x800);
  }

  char* print(){
    puts("[");
    for(int i=0; i<this->size; i++) {
      printf("%lu", this->items[i]);
      if(i!=this->size-1) puts(",");
    }
    puts("]");
  }

  void vt20() {
    for(int i=1; i <= this->size; i++) {
      int item = data[i];
      for(int j=i-1; j>=0 && data[j] > data[i]; j--) {
        data[j+1] = data[j];
      }
      data[j+1] = item;
    }
  }
}

c1s[0x20] // 0x6831C0

int zero_c1(int num) {
  if(num <= 0x1f) {
    C1* c = c1s[num];
    if(c.is_init()) {
      memset(c, 0, 0x828);
      return num;
    }
  }
  return -1;
}

int display_c1(int num) {
  if(num <= 0x1f) {
    C1* c = c1s[num];
    return c->print();
  }
}

int manage_c1_items(int num) {
  if(num <= 0x1f) {
    C1* c = c1s[num];
    if(c->is_init()) {
      int i = (int8_t)prompt("i: ");
      switch(i){
        case 1:
        int ii = (int32_t)prompt("ii: ");
        if(ii <= 0x100) {
          for(int j = c->size; j < 0x100 && ii != 0; j++, ii--) {
            c->items[j] = prompt2("iii: ");
            c->size++;
          }
        }

        case 3:
        c->vt20();

        case 4:
        c->size--;
      }
    }
  }
}
