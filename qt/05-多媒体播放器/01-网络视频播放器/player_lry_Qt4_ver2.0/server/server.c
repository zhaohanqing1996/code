#include "server.h"

int create_txt(void);
//bool isMedirFile(const char *p1);

int isMediaFile(const char *p1)
{
	int i = 0, len1;
	char filename[128] = {0};
	
	if( p1 == NULL)
	{
		perror("文件名检测失败\n");
		return -1;
	}
	len1 = strlen(p1);
	strcpy(filename, p1);//"rang.mp4"  ".mp4" 
	while(filename[i])
	{
		if(filename[i] >= 'A' && filename[i] <= 'Z')
			filename[i] = filename[i] + 'a' - 'z';
		i++;
	}
			
	if(strcmp(filename+len1-4, ".mp3") == 0 || 
	strcmp(filename+len1-4, ".mp4") == 0 || 
	strcmp(filename+len1-4, ".3gp") == 0 || 
	strcmp(filename+len1-5, ".rmvb") == 0 || 
	strcmp(filename+len1-4, ".flv") == 0 || 
	strcmp(filename+len1-4, ".avi") == 0 || 
	strcmp(filename+len1-4, ".wmv") == 0 ||
	strcmp(filename+len1-3, ".rm") == 0 || 
	strcmp(filename+len1-4, ".m4v") == 0 || 
	strcmp(filename+len1-4, ".mpg") == 0 )
		return 1;
		
	return 0;
}


int main(void)
{
	int sd, cli_sd, count = 1;

	while(1)
	{
		if(create_
		txt() == -1)
		{
			perror("创建播放列表文件失败!\n");
			return -1;
		}
		sleep(3);
	}

	return 0;
}

int create_txt(void)
{
	int txt_fd, ret;
	DIR *dp = NULL;
	struct dirent *dirp = NULL;
	char name[128] = {0};

	dp = opendir(SERVER_DIR);
	PERROR(NULL == dp, perror(SERVER_DIR), -1);
	char list_filename[512];
	strcpy(list_filename, SERVER_DIR);
	strcat(list_filename, FILE_NAME);
	txt_fd = open(list_filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	PERROR(-1 == txt_fd, perror(FILE_NAME), -1);


	while((dirp = readdir(dp)) != NULL)
	{
		if(*dirp->d_name == '.')
			continue;

		ret = strlen(dirp->d_name);
		if(isMediaFile(dirp->d_name))
		{
			memcpy(name, dirp->d_name, ret);
			name[ret] = '\n';
		
			write(txt_fd, name, ret + 1);
			memset(name, 0, sizeof(name));
		}
	}

	close(txt_fd);
	closedir(dp);

	return 0;
}

