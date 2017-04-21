/**
 * @brief Recursively fill a task tree
 * @param nr Number of free spaces remaining in info
 *note it seems as if oneweditwork-disk works
 */
int doTaskTree( struct task_struct * rootptr, struct task_info __user * info,
               int nr, int level ){
	int j;
  struct list_head *list;
  
  if ( nr == 0 ){
    // Out of memory!
  	return 0;
  }
  
	info[0] = get_task_info_as_task_struct(rootptr,l);
  
  j = 1;
  
  list_for_each(list, &rootptr->children){ //TODO: figure out how to do this!
  	rootptr = list_entry(list, struct task_struct, sibling);
    j += doTaskTree( rootptr ,&info[j], nr - j, level + 1 );
  }
  return j;
}

SYSCALL_DEFINE3( tasktree, struct task_info __user *, info, int, nr, int, rootpid){
	struct task_struct *root;
	struct task_info *tempinfo;
  
  tempinfo = kmalloc( nr * sizeof( struct task_info), GFP_KERNEL );
  
  root = find_task_by_vpid(rootpid);
  
  doTaskTree( root, tempinfo, nr, 0 );
  
  copy_to_user( info, tempinfo, sizeof( info ) );
}

struct task_info __user get_task_info_as_task_struct(rootptr,l){
	struct task_info tinfo;
  tinfo.pid = rootptr->pid;
  tinfo.parent_pid = rootptr->parent->pid;
  //tinfo.first_child_pid = 3;
  tinfo.state = rootptr->state;
  tinfo.uid = get_uid( rootptr->uid );
  //tinfo.comm = "string\0";
  tinfo.level = l;
  return tinfo;
}
