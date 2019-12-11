" Problem 4 「最大の回文積」 †

" 左右どちらから読んでも同じ値になる数を回文数という. 2桁の数の積で表される回文数のうち, 最大のものは 9009 = 91 × 99 である.

" では, 3桁の数の積で表される回文数の最大値を求めよ.


function! s:is_same(num) abort
  let str = string(a:num)
  let N = strlen(str)

  for i in range(N/2)
    if str[i] != str[N-i-1]
      return 0
    endif
  endfor

  return 1
endfunction

function! s:max(a, b) abort
  if a:a > a:b
    return a:a
  endif
  return a:b
endfunction


let ans = 0
for i in range(100, 999)
  for j in range(100, 999)
    if i*j < ans
      continue
    endif
    if s:is_same(i*j)
      let ans = s:max(ans, i*j)
    endif
  endfor
endfor

echo ans
