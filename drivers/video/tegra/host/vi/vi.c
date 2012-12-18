/*
 * drivers/video/tegra/host/vi/vi.c
 *
 * Tegra Graphics Host VI
 *
 * Copyright (c) 2012, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/export.h>
#include <linux/resource.h>

#include <mach/iomap.h>

#include "dev.h"
#include "bus_client.h"

static int vi_probe(struct nvhost_device *dev,
	struct nvhost_device_id *id_table)
{
	int err = 0;

	err = nvhost_client_device_get_resources(dev);
	if (err)
		return err;

	return nvhost_client_device_init(dev);
}

static int __exit vi_remove(struct nvhost_device *dev)
{
	/* Add clean-up */
	return 0;
}

static int vi_suspend(struct nvhost_device *dev, pm_message_t state)
{
	return nvhost_client_device_suspend(dev);
}

static int vi_resume(struct nvhost_device *dev)
{
	dev_info(&dev->dev, "resuming\n");
	return 0;
}

static struct resource vi_resources = {
	.name = "regs",
	.start = TEGRA_VI_BASE,
	.end = TEGRA_VI_BASE + TEGRA_VI_SIZE - 1,
	.flags = IORESOURCE_MEM,
};

struct nvhost_device *vi_device;

static struct nvhost_driver vi_driver = {
	.probe = vi_probe,
	.remove = __exit_p(vi_remove),
#ifdef CONFIG_PM
	.suspend = vi_suspend,
	.resume = vi_resume,
#endif
	.driver = {
		.owner = THIS_MODULE,
		.name = "vi",
	}
};

static int __init vi_init(void)
{
	int err;

	vi_device = nvhost_get_device("vi");
	if (!vi_device)
		return -ENXIO;

	vi_device->resource = &vi_resources;
	vi_device->num_resources = 1;
	err = nvhost_device_register(vi_device);
	if (err)
		return err;

	return nvhost_driver_register(&vi_driver);
}

static void __exit vi_exit(void)
{
	nvhost_driver_unregister(&vi_driver);
}

module_init(vi_init);
module_exit(vi_exit);
