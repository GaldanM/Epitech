from pyrser             import grammar, meta
from pyrser.directives  import ignore

class parserExpr(grammar.Grammar) :
    entry = "Calc"
    grammar = """
    Calc =
    [
        #createCalc(_) [ Expr:expr #addExpr(_, expr) ]*  eof
    ]

    Expr =
    [
        Product:>_ [ [ '+' | '-' ]:op Product:right #calcRes(_, op, right) ]*
    ]
    Product =
    [
        Value:>_ [ [ '*' | '/' ]:op Value:right #calcRes(_, op, right) ]*
    ]
    Value =
    [
        num:left #setLeft(_, left)
        | '(' Expr:>_ ')'
        | [ '-' | '+' ]:sign Value:value #isNegative(_, sign, value)
    ]
    """

@meta.hook(parserExpr)
def createCalc(self, node) :
    node.exprs = []
    return True

@meta.hook(parserExpr)
def addExpr(self, node, expr) :
    node.exprs.append(expr.expr)
    return True

@meta.hook(parserExpr)
def calcRes(self, node, op, right) :
    op = self.value(op)
    left = node.expr
    if op == '+':
        node.expr = left + right.expr
    elif op == '-':
        node.expr = left - right.expr
    elif op == '*':
        node.expr = left * right.expr
    elif op == '/':
        node.expr = left / right.expr
    return True

@meta.hook(parserExpr)
def setLeft(self, node, left) :
    node.expr = int(self.value(left))
    return True

@meta.hook(parserExpr)
def isNegative(self, node, sign, value) :
    sign = self.value(sign)
    node.expr = value.expr
    if sign == '-' :
        node.expr = -node.expr
    return True