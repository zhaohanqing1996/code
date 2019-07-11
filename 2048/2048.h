class New2048
{
    public:
    New2048()
    {
        for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			a[i][j] = 0;
		num = 0;
    }
    void make_frame();             //打印框架函数。
	void display_num();            //打印数字函数。
	void creat_num();              //随机产生数函数
	void RightMove();              //右移函数
	void LeftMove();               //左移函数
	void UpMove();		       //上移函数
	void DownMove();	       //下移函数
	int cheak();                   //检查游戏是否结束函数
	void clean();                  //清理显示出来的数字
	~New2048(){}

    private:
    int a[4][4];
	int num;
};