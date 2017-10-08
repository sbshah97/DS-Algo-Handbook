#Ternary Search

Ternary search is used for determine the maximum or minimum value of the [unimodal function](https://en.wikipedia.org/wiki/Unimodality#Unimodal_function)

##Algorithm

As suggested by its name, the range [l,r] is divided  into 3 subrange. Therefore, we will have 2 middle value `m1,m2`

- [l,m1]
- [m1+1,m2-1]
- [m2,r]

let `f(x)=2x^2-12x+7`. we will find the minimum value of f(x)

if `f(m1)>f(m2)`, the minimum can't be in the first part. Otherwise it can't be in the last part. So we can cut down 1 part and consider only 2 remaining parts.

##Complexity

Each iteration will reduce the problem size by 2/3.

`T(n) = T(2/3 * n) + Θ(1)`

Which give the time complexity `Θ(log n)`