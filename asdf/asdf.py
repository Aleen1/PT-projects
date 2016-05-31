class StackClass:

    def __init__(self, itemlist=[]):
        self.items = itemlist

    def isEmpty(self):
        if self.items == []:
            return True
        else:
            return False

    def peek(self):
        return self.items[-1:][0]

    def pop(self):
        return self.items.pop()

    def push(self, item):
        self.items.append(item)
        return 0

def parse_rpn(expression):
    stack = []

    for val in expression.split(' '):
        if val in ['-', '+', '*', '/', '^']:
            op1 = stack.pop()
            op2 = stack.pop()
            if val == '-': result = op2 - op1
            if val == '+': result = op2 + op1
            if val == '*': result = op2 * op1
            if val == '/': result = op2 / op1
            if val == '^': result = op2** op1
            stack.append(result)
        else:
            stack.append(float(val))

    return stack.pop()

def infixToPostfix(infixexpr):
    prec = {}
    prec['^'] = 3
    prec['*'] = 2
    prec['/'] = 2
    prec['+'] = 1
    prec['-'] = 1
    opStack = StackClass()
    postfixList = []
    tokenList = infixexpr.split()

    for token in tokenList:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfixList.append(token)
        else:
            while (not opStack.isEmpty()) and \
               (prec[opStack.peek()] >= prec[token]):
                  postfixList.append(opStack.pop())
            opStack.push(token)

    while not opStack.isEmpty():
        postfixList.append(opStack.pop())
    return " ".join(postfixList)

if __name__ == '__main__':
    a = infixToPostfix("2 * 3 + 8")
    result = parse_rpn(a)
    print (result)