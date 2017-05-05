class Bidon:
	zaz = "je suis un pro du python"

	def __init__(self, txt, num = 42, **kwargs):
		self.txt = txt
		self.num = num
		for key, val in kwargs.items():
			setattr(self, key, val)
		return None

def var2listsort(*args):
	mlist = list()
	for val in args:
		mlist.insert(0, val)
	mlist.sort()
	return mlist