/*
 * MyInotify.c
 *
 *  Created on: Jan 5, 2018
 *      Author: philippe
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/inotify.h>

//copy
#include <linux/fcntl.h>
#include <unistd.h>
#include <errno.h>

#define EVENT_LEN (sizeof(struct inotify_event))
#define BUFF_LEN (1024 * (EVENT_LEN + 1))

int copy(const char * from, const char * to) {
	printf("start copy from '%s' to '%s'", from, to);
	int fd_to, fd_from;
	char buf[4096];
	ssize_t nread;
	int saved_errno;

	fd_from = open(from, O_RDONLY);
	if (fd_from < 0)
	return -1;

	fd_to = open(to, O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd_to < 0)
	goto out_error;

	while (nread = read(fd_from, buf, sizeof buf), nread > 0)
	{
		char *out_ptr = buf;
		ssize_t nwritten;

		do {
			nwritten = write(fd_to, out_ptr, nread);

			if (nwritten >= 0)
			{
				nread -= nwritten;
				out_ptr += nwritten;
			}
			else if (errno != EINTR)
			{
				goto out_error;
			}
		} while (nread > 0);
	}

	if (nread == 0)
	{
		if (close(fd_to) < 0)
		{
			fd_to = -1;
			goto out_error;
		}
		close(fd_from);

		/* Success! */
		return 0;
	}

	out_error:
		saved_errno = errno;

		close(fd_from);
		if (fd_to >= 0)
		close(fd_to);

		errno = saved_errno;
		return -1;
}

int main () {
	printf("start");
	int length, i = 0;
	int wd, fd;
	char buff[BUFF_LEN];
	fd = inotify_init();
	if (fd < 0) {
		perror("inotify init");
	}
	wd = inotify_add_watch(fd, "/tmp/tmp", IN_CREATE | IN_DELETE);

	while (1) {
		printf("start reading");
		// handle inotify events
		length = read(fd, buff, BUFF_LEN);
		if (length < 0) {
			perror("read error");
		}
		while (i < length) {
			struct inotify_event * event = (struct inotify_event*) &buff[i];
			if (event->len) {
				if (event->mask & IN_CREATE) {
					if (event->mask & IN_ISDIR) {
						printf("New dir created");
					} else {
						printf("move file %s", event->name);
						char from[50], to[50];
						snprintf(from, 50, "/tmp/tmp/%s", event->name);
						snprintf(to, 50, "/tmp/out/%s", event->name);
						int rc = copy(from, to);
						if (rc < 0){
							perror("copy failed");
						}
					}
				} else if (event->mask & IN_DELETE) {
					if (event->mask & IN_ISDIR) {
						printf("dir removed");
					} else {
						printf("file removed");
					}
				} else {
					perror("unknown action");
				}
			}
			i += EVENT_LEN + event->len;
		}
		break;
	}
	return 0;
}
