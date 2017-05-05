from pyrser             import grammar, meta
from pyrser.directives  import ignore

class parserPseudoIni(grammar.Grammar):
    entry = "Ini"
    grammar = """
        Ini = [ #initAll(_) [ Section:s #newSection(_, s) ] + eof ]
        
        Section = 
        [ 
            #addSection(_)
            '[' id:i #setSectionName(_, i) ']' 
            [ClefValeur:kv #getKeyValue(_, kv)] +
        ]

        ClefValeur = 
        [ 
            id:k '=' valeur:v #fillSection(_, k, v)
        ]

        valeur = 
        [
            id:i #isId(_, i)
            | num:n #isNum(_, n)
            | string:s #isString(_, s)
        ]
    """

@meta.hook(parserPseudoIni)
def initAll(self, ast):
    ast.sections = {}
    return True

@meta.hook(parserPseudoIni)
def newSection(self, ast, sec):
    ast.sections[sec.section_name] = sec.section_values
    return True

@meta.hook(parserPseudoIni)
def addSection(self, ast):
    ast.section_name = None
    ast.section_values = {}
    return True

@meta.hook(parserPseudoIni)
def setSectionName(self, ast, sec):
    ast.section_name = self.value(sec)
    return True

@meta.hook(parserPseudoIni)
def getKeyValue(self, ast, both):
    ast.section_values[both.key] = both.value
    return True

@meta.hook(parserPseudoIni)
def fillSection(self, ast, key, value):
    ast.key = self.value(key)
    ast.value = value.value
    return True

@meta.hook(parserPseudoIni)
def isId(self, ast, id):
    ast.value = self.value(id)
    return True

@meta.hook(parserPseudoIni)
def isNum(self, ast, num):
    ast.value = int(self.value(num))
    return True

@meta.hook(parserPseudoIni)
def isString(self, ast, str):
    ast.value = self.value(str)
    return True