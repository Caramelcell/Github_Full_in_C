---

excalidraw-plugin: parsed
tags: [excalidraw]

---
==⚠  Switch to EXCALIDRAW VIEW in the MORE OPTIONS menu of this document. ⚠==


# Text Elements
template <typename T1, typename T2>
bool FindValue(const T1& Ctn, const T2& val) {
    for (auto i : Ctn) {
        if (i == val) {
            return true;
        }
    }
    for (auto iter = Ctn.begin(); iter != Ctn.end(); ++iter) {
        if (*iter == val) {
            return true;
        }
    }
    return false;
}
// is a bad template,because u cant use "==" to compare two different type when
// you undeclared. so, in that case it just be know who write it.
int main() {
    //map<int, int> m = { 1, 2 };
    set<int> se = { 3 };
    string s = "hello";
    vector<int> v = { 4 };

    bool tof = FindValue<vector<int>,int>(v, 4);
    //bool tof = FindValue<map<int, int>, pair<int, int>>(m, { 1, 2 }); //非法
    cout << tof << endl;
} ^ZbRuHdtw

%%
# Drawing
```compressed-json
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
```
%%