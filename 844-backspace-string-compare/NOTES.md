if (s[i] != t[j])
return false;
i--;
j--;
}
return i == -1 && j == -1;
}
int nextPosition(string& s, int i) {
int count = 0;
while (i >= 0) {
if (s[i] == '#')
count++;
else if (count != 0)
count--;
else
break;
i--;
}
return i;
}
};
// TC: O(len(s) + len(t))
// SC: O(1)
```