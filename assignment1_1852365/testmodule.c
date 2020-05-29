#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

struct task_struct *task;
static int pid = 0;

static int __init procsched_init(void){
	printk(KERN_INFO "Starting kernel module!\n");
	task = get_pid_task(find_get_pid(pid), PIDTYPE_PID);
	if (task != NULL) {
		printk(KERN_INFO "pcount: %lu\n", task->sched_info.pcount);
		printk(KERN_INFO "run_delay: %llu\n", task->sched_info.run_delay);
		printk(KERN_INFO "last_arrival: %llu\n", task->sched_info.last_arrival);
		printk(KERN_INFO "last_queued: %llu\n", task->sched_info.last_queued);
		return 0;
	}
	return -1;
}

static void __exit procsched_cleanup(void){
	printk(KERN_INFO "Cleaning up module.\n");
}
module_init(procsched_init);
module_exit(procsched_cleanup);
module_param(pid, int, 0);
