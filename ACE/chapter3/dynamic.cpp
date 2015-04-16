class Signal_Handler : public ACE_Event_Handler
{
	virtual int handle_signal(int sig, siginfo_t *, ucontext *)
	{
		ACE_Service_Config::reconfig_occurred(1);
		ACE_DEBUG((LM_DEBUG, "execute ace signal handler for signal %d.\n", sig));
		return 0;
	}
};

int main(int argc, char *argv[])
{
	if(ACE_Service_Config::open(argc, argv) == -1)
		ACE_ERROR_RETURN((LM_ERROR, "%p\n", "ACE_Service_Config::open"), -1);

	Signal_Handler handle;
	if(ACE_Reactor::instance()-->register_handler(SIGINT, &handle) == -1)
	{
		ACE_DEBUG((LM_DEBUG, "register signal error.\n"));
		return -1;
	}
	return ACE_Reactor::run_event_loop();
	
}