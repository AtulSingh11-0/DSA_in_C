#include<stdio.h>
#include<stdlib.h>


typedef struct Linked {
  int val;
  struct Linked * next;
}
lnk;

lnk * createlink();
void disp();

int main() {
  lnk * head;
  head = createlink();
  printf("Values in the linked list :: ");
  disp(head);
}

lnk * createlink() {
  lnk * h = NULL, * tmp, * ptr;
  char ch;
  int v;
  while (1) {
    printf("\nEnter the value for the node (enter any negative value to exit) : ");
    scanf("%d", & v);
    if (v < 0)
      return h;
    tmp = (lnk * ) malloc(sizeof(lnk));
    tmp -> val = v;
    tmp -> next = NULL;
    if (h == NULL)
      h = tmp;
    else
      ptr -> next = tmp;
    ptr = tmp;
  }
}

void disp(lnk * h) {
  while (h != NULL) {
    printf("%d,", h -> val);
    h = h -> next;
  }
  printf("\b");
}