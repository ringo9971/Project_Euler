" Problem 3 「最大の素因数」 †

" 13195 の素因数は 5, 7, 13, 29 である.

" 600851475143 の素因数のうち最大のものを求めよ.


let N = 600851475143

let i = 1
while N != i+1
  let i += 1
  if N%i == 0
    let N = N/i
    let i = 1
  endif
endwhile

echo N
echo N
