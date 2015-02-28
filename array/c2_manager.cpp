class C2 : C1 {
  int     is_init;
  char*   data[0x100]; // 0x8
  char**  items;         // 0x808
  int     size;        // 0x810
  int*    print;      // 0x818
  int*    vt20;        // 0x820

  C2() {
    this->a = this->data;
    this->print = c2_vt18;

    this->vt20 = c2_vt20;
    this->size = 0;
    this->is_init = 1;
    memset(this+8, 0, 0x800);
  }

  int is_init() {
    return is_init;
  }

  void print() {
    puts("[");
    for(int i=0; i<this->size; i++) {
      printf("\"%s\"", this->items[i]);
      if(i!=this->size-1) puts(",");
    }
    puts("]");
  }

  void vt20() {
    for(int i=1; i <= this->size; i++) {
      int item = data[i];
      for(int j=i-1; j>=0 && strcmp(item, this->data[j]); j--) {
        data[j+1] = data[j];
      }
      data[j+1] = item;
    }
  }
}

c2s[0x20] // 0x6936C0

int zero_c2(int8_t num) {
  if(num <= 0x1f) {
    C2* c = c1s[num];
    if(c->is_init()) {
      memset(c, 0, 0x828);
      return num;
    }
}

int manage_c2_items(int num) {
  if(num <= 0x1f) {
    C1* c = c1s[num];
    if(c->is_init()) {
      int i = (int8_t)prompt("s: ");
      switch(i) {
      case 2:
        int ii = (int32_t)prompt("ss: ");
        if(ii <= 0x100) {
          for(int j = c->size; j < 0x100 && ii != 0; j++, ii--) {
            c->a08[j] = prompt3("sss: ");
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

