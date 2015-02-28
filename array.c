
int prompt(char* msg) {
  char buf[0x40];
  printf("%s", msg);
  fflush(stdout);
  read(0, buf, 0x3f);
  buf[0x3f] = 0;
  return atoi(buf);
}

int main() {
  write(1, "Array Ops\n", 10);
  int num1 = (int8_t)prompt(" : ");
  if(num1 == 2) {
    int num2 = (int8_t)prompt(" -: ");
    if(num2 == 3) {
      num3 = (int8_t)prompt(" --: ");
      printf("%d\n", fun1(num3));
    } else {

    }

  } else {

  }


  return 0;
}
