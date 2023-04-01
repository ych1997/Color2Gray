# Color2Gray

實作 [Color2Gray: Salience-Preserving Color Removal](https://users.cs.northwestern.edu/~ago820/color2gray/color2gray.pdf) 論文

一般圖片轉為灰階時，會採用亮度值，而壓縮到色彩值，有時候鄰近色彩亮度相近，但顏色大不同時，灰階就會消除掉他們之間的差異，
Color2gray希望灰階圖片可以保留住原圖的差異性，因此參考了鄰域範圍的顏色，來調整灰階圖片中的明暗，藉此保留住彩色圖片的特徵。

## 實作結果：
![image](https://github.com/ych1997/Color2Gray/blob/main/result/圖片%201.png)

![image](https://github.com/ych1997/Color2Gray/blob/main/result/圖片%202.png)

![image](https://github.com/ych1997/Color2Gray/blob/main/result/圖片%203.png)

![image](https://github.com/ych1997/Color2Gray/blob/main/result/圖片%204.png)
