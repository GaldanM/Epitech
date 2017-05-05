from pyrser         import meta, fmt
from pyrser.parsing import node
import collections

scalar = {'bool': bool, 'int': int, 'float': float, 'str': str}

@meta.add_method(node.Node)
def to_dxml(self, size=0, name=".root"):
    items = vars(self)
    items = collections.OrderedDict(sorted(items.items()))
    string = ""
    string += addOpening(name, "object", size)
    for (mName, contenu) in items.items():
        string += addBlock(mName, contenu, size)
    string += addEnding(name, size)
    return string

def addBlock(name, contenu, size):
    string = ""
    if type(contenu).__name__ in scalar:
        string += addContent(name, contenu, size + 4)
    else:
        if isinstance(contenu, node.Node):
            string += contenu.to_dxml(size + 4, name)
        elif isinstance(contenu, list):
            string += isList(name, contenu, size + 4)
        elif isinstance(contenu, dict):
            string += isDict(name, contenu, size + 4)
        elif isinstance(contenu, set):
            string += isSet(name, contenu, size + 4)
        elif isinstance(contenu, bytes):
            string += isBlob(name, contenu, size + 4)
        else:
            string += addContent(name, contenu, size + 4)
    return string

def isList(nameList, mlist, size):
    i = 0
    string = ""
    string += addOpening(nameList, "list", size)
    for elem in mlist:
        name = ".idx __value = " + str(i)
        string += addBlock(name, elem, size)
        i += 1
    if nameList[:4] == '.idx':
        string += addEnding(".idx", size)
    else:
        string += addEnding(nameList, size)
    return string

def isDict(nameDict, mdict, size):
    i = 0
    string = ""
    string += addOpening(nameDict, "dict", size)
    mdict = collections.OrderedDict(sorted(mdict.items()))
    for (key, value) in mdict.items():
        name = ".idx __key = \'" + key + "\'"
        string += addBlock(name, value, size)
        i += 1
    if nameDict[:4] == '.idx':
        string += addEnding(".idx", size)
    else:
        string += addEnding(nameDict, size)
    return string

def isSet(nameSet, mSet, size):
    string = ""
    string += addOpening(nameSet, "set", size)
    mSet = sorted(mSet)
    for elem in mSet:
        name = "\'" + elem + "\'"
        string += addBlock(name, None, size)
    if nameSet[:4] == '.idx':
        string += addEnding(".idx", size)
    else:
        string += addEnding(nameSet, size)
    return string

def isBlob(nameBlob, mBlob, size):
    string = ""
    string += addOpening(nameBlob, "blob", size)
    string += ' ' * (size + 4)
    i = 0
    if len(mBlob) > 0:
        for elem in mBlob:
            if len(mBlob) == 1:
                print(elem)
            string += "%02X" % elem
            i += 1
            if (i < len(mBlob)):
                string += ' '
        string += "\n"
    print (size)
    if nameBlob[:4] == '.idx':
        string += addEnding(".idx", size)
    else:
        string += addEnding(nameBlob, size)
    return string

def addContent(name, value, size) :
    string = ' '*size
    if (value == None) :
        string += '<%s/>' % (name)
    elif isinstance(value, str):
        string += '<%s %s = \'%s\'/>' % (name, type(value).__name__, str(value))
    else:
        string += '<%s %s = %s/>' % (name, type(value).__name__, str(value))
    string += '\n'
    return string

def addOpening(name, type, size):
    string = ' '*size
    string += "<"
    string += name
    string += " type = "
    string += type
    string += ">\n"
    return string

def addEnding(name, size):
    string = ' '*size
    string += "</"
    string += name
    if name == ".root":
        string += ">"
    else:
        string += ">\n"
    return string