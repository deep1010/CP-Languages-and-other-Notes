def main():
    # Incase you have to take input, please take it from file named 'input' (without quotes) [e.g. cat input]
    # Print your final output to console. Do not redirect to another file.
    # E.g. Suppose the question is to print the content of a file.
    #	Your solution should be 'os.system("cat input")'(without single quotes) instead of 'os.system("cat input > output")'. That's it!
    # Your code starts from here...
    lines = []
    with open("input","r") as f:
        lines = f.readlines()
    
    for line in lines:

        line = line.strip("\n").split(",")
        temp = []
        temp.extend(line[0:4])
        temp.append(line[5])
        temp.append('+'+line[4]+'-'+line[6])
        print(','.join(temp))
    return 0

if __name__ == '__main__':
    main()