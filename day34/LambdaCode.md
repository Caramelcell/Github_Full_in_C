# lambda format:

```CPP
[capture-clause] (parameters) ->return-type {
    //body
}
```
^lambdaFormat

# lambda e.g.

```CPP
  string s1 = "hello";
  { string s2("hi"); }

  [&]() {
    // 方括号内用来表示如何捕获本层作用域的变量，=为值传递，&为址传递
    // s2.at();  // error,cant capture
    s1[0] = 'H';
    cout << s1 << endl;
  }();  // auto capture

  [](auto a, string& s1) {
    a = 24;
    s1 = "world";
    cout << a << s1 << endl;
  }(6, s1);  // 即用即丢，爽的一批

  [=](auto a) {
    a = 30;
    // s1 = "hi";  // 值传递无法赋值,编译阶段实例化会检测出来
    cout << a << s1 << endl;
  }(2);

  auto lambda_fun = [](auto a) { cout << a << endl; };
  cout
      << sizeof(lambda_fun)
      << endl;  // sizeof(lambda_fun)等于1,为啥捏，难道说lambda在实例化之前仅仅是一个临时的？
  lambda_fun(s1);
```
^lambdaExample

