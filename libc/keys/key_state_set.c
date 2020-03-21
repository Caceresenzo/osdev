#include <keys.h>

bool
	key_state_set(int code, bool state)
{
	if (state != key_states[code])
		printf(" %d%c ", code, state ? 'P' : 'R');
	key_states[code] = state;
	return (state);
}
