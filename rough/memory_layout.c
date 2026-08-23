
#include <stdio.h>

int b = 10;
static int c;

int main()
{
    int a = 20;
	int sum = b + a;
	printf("sum-%d, c-%d\n", sum, c);
}

=================================
	        High Address
┌─────────────────────────┐
│         Stack           │
│  local variables        │
│  function parameters    │
│  return addresses       │
│          ↓              │
├─────────────────────────┤
│                         │
│       Free Space        │
│                         │
├─────────────────────────┤
│          Heap           │
│  malloc / calloc        │
│  realloc                │
│          ↑              │
├─────────────────────────┤
│     BSS / .bss          │
│  uninitialized globals  │
│  static variables       │
├─────────────────────────┤
│     Data / .data        │
│  initialized globals    │
│  initialized static     │
├─────────────────────────┤
│     Read-only Data      │
│  string literals        │
│  const data (typically) │
├─────────────────────────┤
│     Text / Code         │
│  program instructions   │
└─────────────────────────┘
        Low Address
