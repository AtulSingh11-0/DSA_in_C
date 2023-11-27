#include<stdio.h>
#include<stdlib.h>

typedef struct Linked {
  int val;
  struct Linked * next;
}
lnk;

lnk * insertbeg(lnk * , int);
lnk * insertend(lnk * , int);
lnk * insertatpos(lnk * , int, int);
lnk * del(lnk * , int);
lnk * insertbefore(lnk * , int);
void disp(lnk * );
void insertafter(lnk * , int);

int main() {
  lnk * head = NULL;
  int ch, v, p;
  while (1) {
    printf("\n1) Insert End\n2) Insert begining\n3) Insert at Position\n4) Insert after a certain node\n5) Insert before a certain node\n6) Delete\n7) Display\n8) Exit");
    printf("\n Enter your choice : ");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      printf("\nEnter the value to be inserted : ");
      scanf("%d", & v);
      head = insertend(head, v);
      break;
    case 2:
      printf("\nEnter the value to be inserted : ");
      scanf("%d", & v);
      head = insertbeg(head, v);
      break;
    case 3:
      printf("\nEnter the value to be inserted : ");
      scanf("%d", & v);
      printf("\n Enter the position where to be inserted : ");
      scanf("%d", & p);
      head = insertatpos(head, v, p);
      break;

    case 4:
      printf("\nEnter the value after which you want to Insert : ");
      scanf("%d", & v);
      insertafter(head, v);
      break;
    case 5:
      printf("\nEnter the value before which you want to Insert : ");
      scanf("%d", & v);
      head = insertbefore(head, v);
      break;
    case 6:
      printf("\n Enter the element to be deleted : ");
      scanf("%d", & v);
      head = del(head, v);
      break;
    case 7:
      printf("\n Values in the linked list are : ");
      disp(head);
      break;
    case 8:
      exit(0);
    default:
      printf("\n Wrong choice ");
    }
  }
}

lnk * insertbeg(lnk * h, int g) {
  lnk * temp;
  temp = (lnk * ) malloc(sizeof(lnk));
  temp -> val = g;
  temp -> next = h;
  h = temp;
  return h;
}

lnk * insertend(lnk * h, int g) {
  lnk * temp, * ptr;
  temp = (lnk * ) malloc(sizeof(lnk));
  temp -> val = g;
  temp -> next = NULL;
  if (h == NULL) {
    printf("\n This is going to be first/head node");
    h = temp;
  } else {
    ptr = h;
    while (ptr -> next != NULL)
      ptr = ptr -> next;
    ptr -> next = temp;
  }
  return h;
}
lnk * insertatpos(lnk * h, int g, int p) {
  lnk * ptr, * temp;
  int i;
  temp = (lnk * ) malloc(sizeof(lnk));
  temp -> val = g;
  temp -> next = NULL;
  if (h == NULL) {
    h = temp;
    printf("\n This is going to be first/head node");
  } else {
    if (p == 1) {
      temp -> next = h;
      h = temp;
    } else {
      ptr = h;
      for (i = 1; i < p - 1 && ptr != NULL; i++)
        ptr = ptr -> next;
      if (ptr == NULL) {
        printf("\n There is no such location ");
        return h;
      } else {
        temp -> next = ptr -> next;
        ptr -> next = temp;
      }
    }
  }
  return h;
}

lnk * del(lnk * h, int g) {
  lnk * pre, * ptr;
  if (h == NULL) {
    printf("\nNothing to delete");
    return h;
  } else {
    if (h -> val == g) {

      ptr = h;
      h = h -> next;
    } else {
      ptr = h;

      while (ptr != NULL && ptr -> val != g) {
        pre = ptr;
        ptr = ptr -> next;
      }
      if (ptr == NULL) {
        printf("\n No Such element");
        return h;
      } else {
        pre -> next = ptr -> next;
        free(ptr);
      }
    }
  }
  return h;
}

void disp(lnk * h) {
  while (h != NULL) {
    printf("%d,", h -> val);
    h = h -> next;
  }
  printf("\b");
}

lnk * insertbefore(lnk * h, int v) {
  lnk * ptr, * pre, * temp;
  int p;
  printf("\nEnter the value of the inserting node:");
  scanf("%d", & p);
  temp = (lnk * ) malloc(sizeof(lnk));
  temp -> val = p;
  temp -> next = NULL;
  if (h -> val == v) {
    temp -> next = h;
    h = temp;
  } else {
    ptr = h;
    while (ptr -> val != v && ptr != NULL) {
      pre = ptr;
      ptr = ptr -> next;
    }
    temp -> next = pre -> next;
    pre -> next = temp;
  }
  return h;
}

//insert a node after a particular node

void insertafter(lnk * h, int v) {
  lnk * ptr, * temp;
  int p;
  ptr = h;
  while (ptr -> val != v && ptr != NULL) {
    ptr = ptr -> next;
  }
  printf("\nEnter the value of the inserting node:");
  scanf("%d", & p);
  temp = (lnk * ) malloc(sizeof(lnk));
  temp -> next = NULL;
  temp -> val = p;
  printf("\n====================================");
  if (ptr != NULL) {
    temp -> next = ptr -> next;
    ptr -> next = temp;
  } else
    printf("\nvalue not found");
}