#include "./PainterEngine/PainterEngineHelper.h"

int main()
{
	PX_Initialize("PainterEngine ����̨",800,600);
	//������ʾ����PainterEngine����̨����
	//����̨������Ҫ���ڵ��ԣ�����PainterEngine�ڲ�������StoryVM�ϵ�һ����������ƻ���
	//����̨ʹ��StoryScript�ű���ʹ��PX_ShowConsole��������������̨
	PX_ShowConsole();
	//�йظ������ϸ���������˵���ĵ�
	while(PX_Loop())
	{
	}
}