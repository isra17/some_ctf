/*
 * 1. C3 Management
 * 1.1. New C3
 * 1.2.n. Manage C3 items
 * 1.2.n.1.c.x New C4
 * 1.2.n.2.c.x New C5
 * 1.2.n.4. Delete item
 * 1.2.n.7.a.b. Sub C4
 * 1.2.n.8.a.b. Add C4
 * 1.2.n.9.a.b. Add C5
 * 1.3.n. Delete C3
 * 1.4.n. Print C3
 * 1.5.n. New C1 or C2
 * 1.5.n.2. New C1
 * 1.5.n.3. New C2
 *
 * 2.2.n Manage C1 items
 * 2.2.n.1.c.x. New Int
 * 2.2.n.3. Call vt20
 * 2.2.n.4. Delete item
 * 2.3.n. Delete C1
 * 2.4.n. Print C1
 *
 * 3.2.n Manage C2 items
 * 3.2.n.1.c.x. New String
 * 3.2.n.3. Call vt20
 * 3.2.n.4. Delete item
 * 3.3.n. Delete C2
 * 3.4.n. Print C2
 *
 * 2.0x63. Exit
 */

// Prompt for an unsigned long
int prompt3(char* msg) {
  char* buf = malloc(0x40);
  char buf[0x40];
  printf("%s", msg);
  fflush(stdout);
  read(0, buf, 0x3f);
  return strtoul(buf);
}

// Prompt for a string (Up to 0x3f bytes)
int prompt2(char* msg) {
  char buf[0x40];
  printf("%s", msg);
  fflush(stdout);
  read(0, buf, 0x3f);
  return buf;
}

// Prompt for an int
int prompt(char* msg) {
  char buf[0x40];
  printf("%s", msg);
  fflush(stdout);
  read(0, buf, 0x3f);
  return atoi(buf);
}

int main() {
  write(1, "Array Ops\n", 10);
  int num1 = (int8_t)prompt(" : ");
  int num2;
  switch(num1) {
    case 1:
      switch(prompt("-: ")) {
      case 1:
        printf("%d\n", init_next_c3());
        break;
      case 2:
        num3 = (int8_t)prompt("--: ");
        printf("%d\n", manage_c3_items(num3));
      case 3:
        num3 = (int8_t)prompt("--: ");
        printf("%d\n", zero_c3(num))
      case 4:
        num3 = (int8_t)prompt("--: ");
        printf("%d\n", display_c3_items(num3));
      case 5:
        num3 = (int8_t)prompt("--: ");
        num4 = (int8_t)prompt("--: ");
        printf("%d\n", build_c(num3, num4));
      }

    case 2:
      switch(prompt(" -: ")){
      case 2:
        num3 = (int8_t)prompt(" --: ");
        printf("%d\n", fun1(num3))
      case 3:
        num3 = (int8_t)prompt(" --: ");
        printf("%d\n", zero_c1(num3));
      case 4:
        num3 = (int8_t)prompt(" --: ");
        printf("%d\n", display_c1(num3);
      }

    case 3:
      switch(prompt("-: ")) {
      case 2:
        num3 = (int8_t)prompt("--: ");
        printf("%d\n", fun2(num3));
      case 3:
        num3 = (int8_t)prompt("--: ");
        printf("%d\n", zero_c2(num))
      case 4:
        num3 = (int8_t)prompt("--: ");
        printf("%d\n", display_c2(num3));
      }

    case 99:
      exit(-1);
  }

  return 0;
}


