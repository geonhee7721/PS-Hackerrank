/*
 * ctci-queue-using-two-stacks - Stack and Queue - Medium
 * hackerrank.com/challenges/ctci-queue-using-two-stacks/problem
 */

class MyQueue {
    public:
       stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void pop() {
            if (stack_oldest_on_top.empty()) moveToOldest();
            stack_oldest_on_top.pop();
        }

        int front() {
            if (stack_oldest_on_top.empty()) moveToOldest();
            return stack_oldest_on_top.top();
        }
        
    private:
        void moveToOldest() {
            while (!stack_newest_on_top.empty()) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
};
