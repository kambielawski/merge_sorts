-- 'Ord a =>' indicates my function will compare things, so types must be orderable
-- this function merges two sorted lists to produce a merged sorted list
merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) =
    if x < y 
        then x : merge xs (y:ys) 
        else y : merge (x:xs) ys

-- use merge to merge the sorted first half & last half of the list
merge_sort :: Ord a => [a] -> [a]
merge_sort xs
    | length xs <= 1 = xs
    | otherwise      = merge (merge_sort (take (length xs `div` 2) xs)) -- first half
                             (merge_sort (drop (length xs `div` 2) xs)) -- last half

-- checks if the head of the list is less than the head of the list's tail
-- if yes, recurse, otherwise return False because it's unsorted
sorted :: Ord a => [a] -> Bool
sorted [] = True
sorted (x:xs)
    | xs == []      = True
    | x <= (head xs) = sorted xs
    | otherwise     = False
