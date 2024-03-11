Intution :- 
  There will be at least one node in the tree accordin to the constraints.
  Given that there is one node the initial vacancy will be 1.
  Each node whether its null of not will take 1 vacancy for themselves.
  One node that is not null and has some value can create 2 vacancy.
  One node that is null cannot create any vacancy

Time Complextiy :- O(N)
Space Complexity :- O(1)

YouTube Video Link :- https://www.youtube.com/watch?v=RzNYwhSQjHQ

code :-
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        nodes = preorder.split(',')
        vacancy = 1
        # print(nodes)
        for node in nodes:
            vacancy -= 1
            if vacancy<0:   
                return False
            if node != '#':
                vacancy += 2
        
        return (vacancy == 0)
