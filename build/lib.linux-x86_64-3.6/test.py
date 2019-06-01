import myModule

with open("output.txt", "rb") as text_file:
	a = text_file.readline();

print (a)
print(myModule.castString(a,6))
