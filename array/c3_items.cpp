class C4 {
  int n;
  int* to_str;
  int* add;
  int* sub;

  C4(int n) {
    dst->n = n;
    dst->to_str = to_str;
    dst->add = c4_add;
    dst->sub = c4_vt18;
  }

  char* to_str() {
    char* buf = malloc(0x40);
    snprintf(buf, 0x40, "%lu", this->n);
  }

  void add(C4* other) {
    this->n += other->n;
  }

  void sub(C4* other) {
    this->n -= other->n;
  }
}

class C5 {
  int* buf;
  int* to_str;
  int* add;

  C5(int* buf) {
    dst->buf = buf;
    dst->to_str = to_str;
    dst->add = add;
  }

  char* to_str() {
    return buf;
  }

  void add(C5 *other) {
    int len = strlen(this->buf) + strlen(other->buf);
    char* buf = realloc(this->buf, len);

    r12 = strlen(other->buf);
    memcpy(buf + strlen(this->buf), other->buf, strlen(other->buf)
    this->buf = buf;
  }
}

class C3Item {
  int type; // 8
  C4 c4;    // 32
  C5 c5;    // 24
}

