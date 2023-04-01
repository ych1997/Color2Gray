# Color2Gray

實作 [Color2Gray: Salience-Preserving Color Removal](https://users.cs.northwestern.edu/~ago820/color2gray/color2gray.pdf) 論文

一般圖片轉為灰階時，會採用亮度值，而壓縮到色彩值，有時候鄰近色彩亮度相近，但顏色大不同時，灰階就會消除掉他們之間的差異，
Color2gray希望灰階圖片可以保留住原圖的差異性，因此參考了鄰域範圍的顏色，來調整灰階圖片中的明暗，藉此保留住彩色圖片的特徵。

## 實作結果：

### 結果1：

原圖中夕陽與背景的色彩亮度相近，因此透過photoshop轉成灰階圖後，夕陽與水中倒映變得很不明顯，透過Color2Gray，則能夠保存原先夕陽與水中倒映的特徵。

<img align="center" src="https://github.com/ych1997/Color2Gray/blob/main/result/圖片%201.png" width="500">  

### 結果2：

原圖中背景山坡為兩種不同的綠色，但色彩亮度相近，因此透過photoshop轉成灰階圖後，變得不明顯
，透過Color2Gray，則能夠保存兩種不同顏色山坡的特徵。

<img align="center" src="https://github.com/ych1997/Color2Gray/blob/main/result/圖片%202.png" width="500">  

### 結果3：

原圖中的色彩亮度都很相近，因此原圖中綠色條紋特徵，再經過photoshop轉成灰階圖後，完全看不到
，透過Color2Gray，則能夠保存綠色條紋的特徵。

<img align="center" src="https://github.com/ych1997/Color2Gray/blob/main/result/圖片%204.png" width="500">  

### 其他結果：

<img align="center" src="https://github.com/ych1997/Color2Gray/blob/main/result/圖片%203.png" width="500">  



