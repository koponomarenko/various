# Write a program that prompts for a file name, then opens that file and reads through the file, looking for lines of the form:
# X-DSPAM-Confidence:    0.8475
# Count these lines and extract the floating point values from each of the lines and compute the average of those values and produce an output as shown below.
# Use the file name mbox-short.txt as the file name


fname = raw_input("Enter file name: ")
try:
    fh = open(fname)
except:
    print 'Wrong file name'
    exit()

count = 0
total = 0

for line in fh:
    if not line.startswith("X-DSPAM-Confidence:"):
        continue
    count += 1
    
    # geting number from string
    pos = line.find(':')
    try:
        numb = float(line[pos + 1:])
    except:
        print 'there is no number in line: ' + line
        continue
    total += numb


print "Average spam confidence: " + str(total / count)
