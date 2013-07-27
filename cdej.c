#include <linux/cdrom.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define CDDEVICE "/dev/cdrom"

int main( int argc, char **argv)
{
	int cdrom;
	cdrom = open(CDDEVICE,O_RDONLY | O_NONBLOCK);
		while( cdrom > 0 )
		{
			ioctl(cdrom,CDROMEJECT,0);
			ioctl(cdrom,CDROMCLOSETRAY,0);
		}
	close(cdrom);
}
