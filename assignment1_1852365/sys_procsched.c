#include <linux/pid.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/kernel.h>

struct proc_segs
{
  unsigned long mssv;
  unsigned long pcount;
  unsigned long long run_delay;
  unsigned long long last_arrival;
  unsigned long long last_queued;
};

asmlinkage long sys_procsched(int pid, struct proc_segs *info)
{
  struct task_struct *task = NULL;
  task = pid_task(find_vpid(pid), PIDTYPE_PID);

  if(task==NULL)
    {
      return -1;
    }

  info->mssv = 1852365;
  info->pcount = (task->sched_info).pcount;
  info->run_delay = (task->sched_info).run_delay;
  info->last_arrival = (task->sched_info).last_arrival;
  info->last_queued = (task->sched_info).last_queued;

  return 0;
}
