from cnorm.parsing.declaration import Declaration
from cnorm.passes import to_c
from cnorm import nodes

def marvin(ast):
	tab = []
	for node in ast.body:
		s = fillDecType(node)
		if len(node._name) > 0:
			s += node._name + " est "
		else:
			s += "tout seul dans son coin, est "
		for var in vars(node):
			if var == "_ctype":
				txt = str(type(node._ctype))
				if txt.count("Composed"):
					s += readCtype(node._ctype)
				if txt.count("Primary"):
					s += readExpr(node._ctype, node)
					if hasattr(node, "_assign_expr"):
						s += "qui est initialise a une certaine valeur mais ca me saoule"
				if txt.count("Func"):
					s += readFunc(node._ctype)
		tab.insert(len(tab), s)
	return tab[0][:-1]

def fillName(node):
	s = ""
	if len(node._name) > 0:
		s += node._name + " est "			
	else:
		s += "tout seul dans son coin, est "

def fillDecType(node):
	if str(type(node._ctype)).count("Primary"):
		if hasattr(node, "_assign_expr"):
			return "je declare! "
	if hasattr(node, "Func"):
		return "je declare! "
	return "je defini! "

def fillType(node):
	txt = ""
	if hasattr(node, "_identifier"):
		if node._identifier == "int":
			if hasattr(node, "_specifier"):
				if node._specifier == nodes.Specifiers.SHORT:
					txt += "un entier court "
				elif node._specifier == nodes.Specifiers.LONGLONG:
					txt += "un entier a la super-jack "
				elif node._specifier == nodes.Specifiers.LONG:
					txt += "un entier a la jack "
				else:
					txt += "un entier "
		elif node._identifier == "float":
			txt += "un floattant "
		elif node._identifier == "double":
			txt += "un flottant double precision "
	return txt

def fillParams(node):
	txt = ""
	if hasattr(node, "_storage"):
		if node._storage == nodes.Storages.STATIC:
			txt += "definie localement "
		if node._storage == nodes.Storages.REGISTER:
			txt += "stocker dans un registre "
	if hasattr(node, "_sign"):
		if node._sign == nodes.Signs.UNSIGNED:
			txt += "positif ou nul "
	if str(type(node._decltype)).count("Qual"):
		txt += readExpr(node._decltype, None)
	if str(type(node._decltype)).count("Pointer"):
		txt += readPointer(node)
	if hasattr(node, "_qualifier"):
		if node._qualifier == nodes.Qualifiers.CONST:
			txt += "constant "
		if node._qualifier == nodes.Qualifiers.VOLATILE:
			txt += "toujours mis a jour lorsqu'on y accede "
	if str(type(node._decltype)).count("Paren"):
		txt += readParen(node._decltype)
	if str(type(node._decltype)).count("Array"):
		txt += readArray(node._decltype)
	return txt
	
def readCtype(node):
	s = fillType(node)
	s += fillParams(node)
	return s

def readExpr(node, valueNode):
	if hasattr(valueNode, "_colon_expr"):
		s = "un champs de bit "
	else:
		s = fillType(node)
	s += fillParams(node)
	return s

def readPointer(node):
	s = "pointeur sur "
	s += fillType(node)
	return s

def readParen(node):
	s = fillParams(node)
	s += fillType(node)
	return s

def readFunc(node):
	s = fillType(node)
	s += fillParams(node)
	return s

def readArray(node):
	s = fillType(node)
	s += fillParams(node)
	return s