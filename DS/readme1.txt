首先建一個structure array(以下簡稱grade)用來存放號碼、名字、數學成績、國文成績。
swap在sorting的時候會用到
用fopen開檔，名在command line輸入，如果沒有輸入檔名將會輸出"fopen failed"
在遇到EOF之前將測資一行一行讀到對應的buf變數或陣列裡，然後存到grade
用一個指標指向grade的開頭，把他從頭到尾printf一遍
接下來是action menu，沒規定是否重複執行所以讓他重複了，寫在while迴圈裡
對應四種case分別在排序時針對不同對象去做排序判斷的依據，這邊是用bubble sort
數字由小排到大，字母由A排到Z。
原本是打算用qsort的，執行上比較有效率，可是突然不想寫四種compare function就偷懶了☆
排序完後印出結果再度回到action menu
要結束程式只能用ctrl+c了
其實可以加一個case'5':結束程式，但是作業規定裡的action menu沒有這項我就不多此一舉了。