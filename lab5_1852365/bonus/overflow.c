#include <stdio.h>
void func (unsigned long number) {
  unsigned long local_f = number;
  printf("%lu --> %p\n", local_f, &local_f);
  local_f--;
  while(1) {
    func(local_f);
  }
}
int main() {
  func(10);
}
