#include "./PainterEngine/PainterEngineHelper.h"

int main()
{
	PX_Initialize("PainterEngine �����ı�",800,600);
	//PainterEngine�����ı��ǳ���
	PX_FontDrawText(PX_GetSurface(),300,300,"�����ʹ��PainterEngine���Ƶ�����",PX_COLOR(255,0,0,0),PX_FONT_ALIGN_XLEFT);
	//���һ��������ARGB��ɫ���Լ������ͺ���
	while(PX_Loop())
	{
	}
}