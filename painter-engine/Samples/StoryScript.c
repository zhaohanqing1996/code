#include "./PainterEngine/PainterEngineHelper.h"

px_bool VM_DrawLine(PX_ScriptVM_Instance *ins)//host �������������ָ�ʽ
{
	PX_GeoDrawLine(PX_GetSurface(),\
		PX_ScriptVM_HOSTPARAM(ins,0)._int,\
		PX_ScriptVM_HOSTPARAM(ins,1)._int,\
		PX_ScriptVM_HOSTPARAM(ins,2)._int,\
		PX_ScriptVM_HOSTPARAM(ins,3)._int,\
		2,\
		PX_COLOR(255,0,0,255)
		);
	return PX_TRUE;
}


int main()
{
	//��������������PainterEngine��StoryScript��ʹ��
	//StoryScript��PainterEngine�м��ɵ�һ���ű�����,��PainterEngine�м�����StoryScript�ı�������ִ�����������
	//ͨ����д�ű�,�����Ƴ�����߼�����,����ű������߼��ķ�������Ϸ�����е�ʹ���Ѿ��ǳ��ձ���,��������ʹ�ýű�������һ��������

	//�ȱ�дһ���ű�
	//��tools��,�ṩ�˶�StoryScript�ı��빤��
	//Script.bin�Ǳ������ļ�,������������д�ڲ�������
	PX_ScriptVM_Instance Ins;//�����ʵ����
	px_memory shell;//�������ؽű�
	if (!PX_Initialize("StoryScriptʾ��",800,600))//��ʼ��PainterEngine
	{
		return 0;
	}
	PX_MemoryInit(PX_GetMP(),&shell);
	PX_LoadScriptFromFile(&shell,"Script.bin");//���ر���shell�ļ�
	PX_ScriptVM_InstanceInit(&Ins,PX_GetMP(),shell.buffer,shell.usedsize);//��ʼ�������,�����ű����л���
	PX_ScriptVM_RegistryHostFunction(&Ins,"DRAWLINE",VM_DrawLine);//ע��Host����
	PX_ScriptVM_InstanceRunFunction(&Ins,0,PX_NULL,"DrawTriangle",0);//���ýű��е�DrawTriangle����,��Ȼ,StoryScript�Ǵ�Сд�޹صĽű�,д��DRAWTRIANGLEҲ����

	while(PX_Loop());
}