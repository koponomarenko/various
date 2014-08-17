# Write a program to read through the mbox-short.txt and figure out who has sent the greatest number of mail messages. The program looks for 'From ' lines and takes the second word of those lines as the person who sent the mail. The program creates a Python dictionary that maps the sender's mail address to a count of the number of times they appear in the file. After the dictionary is produced, the program reads through the dictionary using a maximum loop to find the most prolific committer.


name = raw_input("Enter file: ")
if len(name) < 1:
    name = "data/mbox-short.txt"
fh = open(name)
stat = dict()
for line in fh:
    if line.startswith('From') and not line.startswith('From:'):
        words = line.split()
        stat[words[1]] = stat.get(words[1], 0) + 1

max_emails = None
sender = None
for key, value in stat.items():
    if max_emails is None:
        max_emails = value
        sender = key
    elif max_emails < value:
        max_emails = value
        sender = key

print sender, max_emails
