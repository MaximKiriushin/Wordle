import sqlite3


def main():
	
	conn = sqlite3.connect('wordleList') 

	c = conn.cursor()

	with open("list.txt") as textFile:
		for word in textFile:
			insert(word[:5], c, conn)

	conn.close()


def insert(word, c, conn):
	with conn:
		c.execute("INSERT INTO WORDS VALUES (?, ?)", (textToAscii(word), word))


def textToAscii(word):
    return ''.join(str(ord(c)) for c in word)



if __name__ == "__main__":
	main()