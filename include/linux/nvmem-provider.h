/*
 * nvmem framework provider.
 *
 * Copyright (C) 2015 Srinivas Kandagatla <srinivas.kandagatla@linaro.org>
 * Copyright (C) 2013 Maxime Ripard <maxime.ripard@free-electrons.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef _LINUX_NVMEM_PROVIDER_H
#define _LINUX_NVMEM_PROVIDER_H

#include <linux/nvmem-consumer.h>

struct nvmem_device;

struct nvmem_config {
	struct device		*dev;
	const char		*name;
	int			id;
	struct module		*owner;
	struct nvmem_cell_info	*cells;
	int			ncells;
};

#if IS_ENABLED(CONFIG_NVMEM)

struct nvmem_device *nvmem_register(struct nvmem_config *cfg);
int nvmem_unregister(struct nvmem_device *nvmem);

#else

static inline struct nvmem_device *nvmem_register(struct nvmem_config *cfg)
{
	return ERR_PTR(-ENOSYS);
}

static inline int nvmem_unregister(struct nvmem_device *nvmem)
{
	return -ENOSYS;
}

#endif /* CONFIG_NVMEM */

#endif  /* ifndef _LINUX_NVMEM_PROVIDER_H */
