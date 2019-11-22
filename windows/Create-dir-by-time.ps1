$usedate = "{0:yyyy-MMdd}" -f (Get-Date)   #获取当前计算机日期,并存储为yy-mm-dd格式
$newfile = Get-ChildItem  -name * -include $usedate
if ( $newfile -eq $null ) 
{
    New-Item -Name $usedate -ItemType Directory  #如果当前目录下没有此文件则创建   
}
else
{
    write-host "$newfile 已经存在"
}