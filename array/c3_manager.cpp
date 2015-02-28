class C3 { // size == 0x4018
  int is_init;
  C3Item data[0x100];  // 0x8
  int size             // 0x4008
  void (*print)();     // 0x4010

  C3() {
    this->is_init = 1;
    this->print = print;
    this->size = 0;
    memset(this+8, 0, 0x4000);
  }

  int add_c1(C1 c1) {
    if(this->size <= 0x100) {
      for(i=0; i < this->size; i++) {
        C3Item item = this->data[i];
        if(item.type == 2) {
          c1->items[i] = item.c4.n
          c1->size++;
        } else {
          return -1;
        }
      }

      // Delete C1
      return 0;
    }
  }

  int add_c2(C2) {
    // Comme add_c1, mais pour c2
  }

  int print() {
    size = this->size;
    data = this->data;
    puts("[");
    for(int i=0; i<this->size; i++) {
      C3Item = this->data[i];
      if(item->type != 2) {
        printf("\"%s\"", item.c5.to_str());
      } else {
        printf("%s", item.c4.to_str());
      }
      if(i != this->size-1) puts(",");
    }
    puts("]");
  }
}

int init_next_c3() {
  for(int i=0; i<=0x1f; i++) {
    C3 c = c3s[i];
    if(!c->is_init()) {
      c->init();
      return i;
    }
  }
}


int manage_c3_items(int num) {
  if(num <= 0x1f) {
    C3 *c3 = c3s[num];
    if(c3->is_init()) {
      int n = (int8_t)prompt("*: ");
      switch(n) {
      // Create ** new C4 in C3
      case 1:
        int nn = prompt("**: ");
        if(nn <= 0x100) {
          for(c3->size <= 0xff && nn; c3->size++, nn--) {
            char* item = &c3->data[c3->size].c4;
            c3->data[c3->size].type = 2;
            int val = prompt2("***: ");
            new_c4(val, item);
          }
        }

      case 2:
        int nn = prompt("**: ");
        if(nn <= 0x100) {
          for(c3->size <= 0xff && nn; c3->size++, nn--) {
            char* item = &c3->data[c3->size].c5;
            c3->data[c3->size].type = 3;
            int val = prompt3("***: ");
            new_c5(val, item);
          }
        }

      case 4:
        c3->size--;

      case 7:
        n1 = prompt("**: ");
        n2 = prompt("**: ");
        if(n1 < c3->size && n2 < c3->size) {
          if(c3->data[n1].type == 2 &&
                c3->data[n2].type == 2) {
            C4 *c4_1 = &c3->data[n1].c4;
            C4 *c4_2 = &c3->data[n2].c4;
            c4_1->sub(c4_2);
          }
        }

      case 8:
        n1 = prompt("**: ");
        n2 = prompt("**: ");
        if(n1 < c3->size && n2 < c3->size) {
          if(c3->data[n1].type == 2 &&
                c3->data[n2].type == 2) {
            C4 *c4_1 = &c3->data[n1].c4;
            C4 *c4_2 = &c3->data[n2].c4;
            c4_1->add(c4_2);
        }

      case 9:
        n1 = prompt("**: ");
        n2 = prompt("**: ");
        if(n1 < c3->size && n2 < c3->size) {
          if(c3->data[n1].type == 3 &&
                c3->data[n2].type == 3) {
            C5 *c5_1 = &c3->data[n1].c5;
            C5 *c5_2 = &c3->data[n2].c5;
            c5_1->add(c5_2);
          }
        }
      }
    }
  }
}


int build_c(int c3_id, int type) {
  if(c3_id < 0x1f) {
    C3 *c3 = c3s[c3_id];
    if(type == 2) {
      int c1_i = init_next_c1();
      C1 *c1 = c1s[i];
      if(!c3->init_c1_from_c3(c1)) {
        zero_c1(c1);
      }
    } else if(type == 3) {
      // Same as previous block except for C2s
    }
  }
}
