#!/usr/bin/env python
# encoding: utf-8

import os

class Getmem(object):
    ''' get member'''
    def __init__(self, dirname, url="https://leetcode.com/problems/"):
        self.dirname = dirname
        self.url = url
        self.num = ""
        self.title = ""
        self.solution = ""
        self.note = ""
        self.difficulty = ""
        self.tag = ""
        self.get_all()

    def get_num(self):
        self.num = self.dirname[:3]

    def get_title(self):
        title_name = self.dirname[4:]
        title_url = os.path.join(self.url, title_name.replace(" ", "-"))
        self.title = "[%s](%s)" % (title_name, title_url)

    def get_solution(self):
        myurl = dirname.replace(" ", "%20")
        c_url = "%s/solution.h" % myurl
        python_url = "%s/solution.py" % myurl
        self.solution = "[C](%s)[Python](%s)" % (c_url, python_url)

    def get_note(self):
        myurl = dirname.replace(" ", "%20")
        note_url = myurl
        self.note = "[NOTE](%s)" % note_url

    def get_difficulty(self):
        pass

    def get_tag(self):
        pass

    def get_all(self):
        self.get_num()
        self.get_title()
        self.get_solution()
        self.get_note()
        self.get_difficulty()
        self.get_tag()

if __name__ == "__main__":
    '''generate readme file by automatic'''

    head = '''
LeetCode
========
LeetCode solutions in C and Python2.

|NO.|Title|Solution|Note|Difficulty|Tag|
|---|-----|--------|----|----------|---|


'''

    path = '.'
    dirnames = os.listdir(path)
    sfile = "README_NEW.test"

    with open(sfile, "w") as f:
        f.write(head)
        dirs = os.listdir(path)
        for dirname in sorted(dirs,key=lambda x:x[:3]):
            if not dirname.startswith('.') and os.path.isdir(dirname):
                print dirname
                g = Getmem(dirname)
                mem = (g.num, g.title, g.solution, g.note, g.difficulty, g.tag)
                text = "|%s|%s|%s|%s|%s|%s|\n" % mem
                f.write(text)
