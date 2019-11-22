#include "./PainterEngine/PainterEngineHelper.h"

PX_Object *PushButton,*Edit;

//�¼�������,ע���������������������������ָ�ʽ
px_void PX_OnButtonDown(PX_Object *pObject,PX_Object_Event e,px_void *ptr)
{
	//���ǵ�����ʾ���������ı�
	MessageBoxA(0,PX_Object_EditGetText(Edit),"",MB_OK);
}

int main()
{
	PX_Initialize("PainterEngine UI�ؼ�",800,600);
	//���ڸ���Ҵ�����ʱPainterEngine��UI�ؼ�����,PainterEngine�ж�����ÿؼ�,�������PX_Object.h���ҵ�����
	//��ڿ�������Ҫ��������д����Ե������ؼ�,�����Ͱ�ť

	//�Ƚ����°�ť���÷�,ʹ�ð�ťǰ,������Ҫ�ȶ���һ��PX_Object����
	//������ť
	PushButton=PX_Object_PushButtonCreate(PX_GetUiRoot()->mp,PX_GetUiRoot(),300,300,96,24,"ȷ��",PX_COLOR(255,0,0,255));
	//���ǿ��Գ��Ըı䰴ť����ʽ
	PX_Object_GetPushButton(PushButton)->style=PX_OBJECT_PUSHBUTTON_STYLE_ROUNDRECT;

	//��Ȼ,��ɫ֮���Ҳû����
	PX_Object_GetPushButton(PushButton)->BorderColor=PX_COLOR(255,255,0,0);
	PX_Object_GetPushButton(PushButton)->CursorColor=PX_COLOR(255,255,128,128);

	//������Ҫ��Ӱ�ť�Ĵ����¼�,����PainterEngine�¼��������,�뷭�İ����ĵ�
	//�󲿷������,���Ǵ���ť��click�¼�

	PX_ObjectRegisterEvent(PushButton,PX_OBJECT_EVENT_CURSORCLICK,PX_OnButtonDown,PX_NULL);

	//���Լ��ϸ��༭��
	Edit=PX_Object_EditCreate(PX_GetUiRoot()->mp,PX_GetUiRoot(),300,200,200,24,PX_COLOR(255,0,0,255));


	while(PX_Loop())
	{
	}
}