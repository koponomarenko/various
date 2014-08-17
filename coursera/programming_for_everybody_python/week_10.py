# Write a program to read through the mbox-short.txt and figure out the distribution by hour of the day for each of the messages. You can pull the hour out from the 'From ' line by finding the time and then splitting the string a second time using a colon.
#   From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008
# Once you have accumulated the counts for each hour, print out the counts, sorted by hour as shown below. Note that the autograder does not have support for the sorted() function.

name = raw_input("Enter file: ")
if len(name) < 1:
    name = "data/mbox-short.txt"
fh = open(name)

stat = dict()
for line in fh:
    if line.startswith('From') and not line.startswith('From:'):
        words = line.split()
        time = words[5].split(':')
        stat[time[0]] = stat.get(time[0], 0) + 1

# create a list of tuples from the dictionary
lst =  stat.items()

# sort by key
lst.sort()

for key, val in lst:
    print key, val
