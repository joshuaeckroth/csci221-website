
x = 5

q = let y = x + 10
    in y + 3

r = z * x + w
    where w = 4
          z = 3

f c = c*c

-- main = do putStrLn "hello"
--           putStrLn (show (f 3))
--           putStrLn (show r)

-- t = main

---

x2 = 55
-- x2 = 75

---

average_three_values x y z = (x + y + z) / 3.0

---

-- main = let x = 5
--            y = x * x
--        in putStrLn "hello"

---

main = do putStr "Type your name: "
          name <- getLine
          putStr "Your name is: "
          putStrLn name
          putStr "Type a number: "
          num_str <- getLine
          let num  = read num_str
              num2 = num * num + 5
            in do putStr "New number: "
                  putStrLn (show num2)
          putStrLn "We're done."

---

xs = [1, 3, 5, 2, 6, 2, 5, 8]

my_mapping_fn n = 2*n

xs2 = map my_mapping_fn xs

my_filtering_fn n = (n `mod` 2 == 0)

xs3 = filter my_filtering_fn xs

my_foldr_fn m n = (m * n + 5)

-- foldr needs three arguments: the folding fn, an initial value (for
-- the first folding fn call), and the list
xs4 = foldr my_foldr_fn 10 xs

           
          
