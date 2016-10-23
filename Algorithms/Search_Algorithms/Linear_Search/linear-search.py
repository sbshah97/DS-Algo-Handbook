def main():
	a=[]
	size=0
	print "Enter size: "
	size= input()
	print "Enter the elements: "
	for i in range(0,size):
		x=input()
		a.append(x)
	print "Enter the element you want to search for: "
	y=input()
	flag=0
	for i in range(0,size):
		if a[i] == y:
			print "Element found at position "+ str(i+1)
			flag=1
	if flag==0:
		print "Element not found"

if __name__ == "__main__":
	main()