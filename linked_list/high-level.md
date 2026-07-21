| Problem                    | Pattern Used                               |
| -------------------------- | ------------------------------------------ |
| Find Middle                | Fast & Slow Pointer                        |
| Detect Loop                | Fast & Slow Pointer                        |
| Nth Node from End          | Two Pointers                               |
| Reverse List               | Three Pointers (`prev`, `current`, `next`) |
| Merge Sorted Lists         | Dummy + Tail                               |
| Remove Duplicates (Sorted) | Single Traversal                           |


| Problem                        | Logic                                                                                                                    | Core Code                                                                                                      | Time   | Space |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------- | ------ | ----- |
| **Find Middle**                | One pointer moves 1 step (`slow`), another moves 2 steps (`fast`). When `fast` reaches the end, `slow` is at the middle. | `while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }`                                         | O(n)   | O(1)  |
| **Detect Loop**                | Use Fast & Slow pointers. If there is a loop, they will eventually meet.                                                 | `while(fast && fast->next){ slow=slow->next; fast=fast->next->next; if(slow==fast) return 1; }`                | O(n)   | O(1)  |
| **Nth Node from End**          | Move `first` pointer `n` nodes ahead. Then move both pointers together until `first` reaches `NULL`.                     | `for(i=0;i<n;i++) first=first->next; while(first){ first=first->next; second=second->next; }`                  | O(n)   | O(1)  |
| **Reverse List**               | Save the next node, reverse the current node's link, then move all three pointers forward.                               | `next=curr->next; curr->next=prev; prev=curr; curr=next;`                                                      | O(n)   | O(1)  |
| **Merge Sorted Lists**         | Compare both lists, append the smaller node to `tail`, then advance that list.                                           | `if(l1->data<=l2->data){ tail->next=l1; l1=l1->next; } else { tail->next=l2; l2=l2->next; } tail=tail->next;`  | O(m+n) | O(1)  |
| **Remove Duplicates (Sorted)** | Compare current node with the next. If equal, delete the next node; otherwise move forward.                              | `if(curr->data==curr->next->data){ temp=curr->next; curr->next=temp->next; free(temp);} else curr=curr->next;` | O(n)   | O(1)  |

