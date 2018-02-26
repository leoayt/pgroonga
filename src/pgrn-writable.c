#include "pgroonga.h"

#include "pgrn-global.h"
#include "pgrn-writable.h"

static grn_ctx *ctx = &PGrnContext;

#define KEY "pgroonga_writable"
#define KEY_SIZE (sizeof(KEY) - 1)
#define FALSE_VALUE "false"
#define FALSE_VALUE_SIZE (sizeof(FALSE_VALUE) - 1)

bool
PGrnIsWritable(void)
{
	const char *value = NULL;
	uint32_t valueSize = 0;

	if (!PGrnGroongaInitialized)
	{
		return true;
	}

	grn_config_get(ctx, KEY, KEY_SIZE, &value, &valueSize);
	return valueSize == 0;
}

void
PGrnSetWritable(bool newWritable)
{
	if (!PGrnGroongaInitialized)
	{
		return;
	}

	if (newWritable)
		grn_config_delete(ctx, KEY, KEY_SIZE);
	else
		grn_config_set(ctx, KEY, KEY_SIZE, FALSE_VALUE, FALSE_VALUE_SIZE);
}
