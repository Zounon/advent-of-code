day1 :: IO ()
day1 = do
    contents <- readFile "./input"
    let instructionsInt =  (map parseLineToInt (lines contents))
    let instructionsTuple =  (map parseLineToTuple (lines contents))
    print (countZeros (scanl updateVal 50 instructionsInt))
    print (countZeros (scanl updateVal 50
        (concatMap (uncurry replicate) instructionsTuple)))

    
parseLineToInt :: String -> Int
parseLineToInt (sign:num) =
    let n = read num :: Int in (n * (if sign == 'R' then 1 else -1))

parseLineToTuple :: String -> (Int,Int)
parseLineToTuple (sign:num) =
    let n = read num :: Int in (n, (if sign == 'R' then 1 else -1))


updateVal :: Int -> Int -> Int
updateVal acc val = (acc + val) `mod` 100

countZeros :: [Int] -> Int
countZeros = length . filter (==0)










