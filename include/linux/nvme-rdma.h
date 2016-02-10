/*
 * Copyright (c) 2015 Mellanox Technologies. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#ifndef _LINUX_NVME_RDMA_H
#define _LINUX_NVME_RDMA_H

enum nvme_rdma_cm_fmt {
	NVME_RDMA_CM_FMT_1_0 = 0x0,
};

/* XXX: Based on the latest status codes draft by Dave */
enum nvme_rdma_cm_status {
	NVME_RDMA_CM_INVALID_REQ = 1,
	NVME_RDMA_CM_INVALID_RECFMT,
	NVME_RDMA_CM_INVALID_QID,
	NVME_RDMA_CM_INVALID_CQSIZE,
	NVME_RDMA_CM_INVALID_SQSIZE,
	NVME_RDMA_CM_INVALID_CNTLID,
	NVME_RDMA_CM_INVALID_HOSTSID,
	NVME_RDMA_CM_CNTL_NOT_FOUND,
	NVME_RDMA_CM_NO_RSC,
};

/**
 * struct nvme_rdma_cm_req - rdma connect request
 *
 * @recfmt:        format of the RDMA Private Data
 * @qid:           queue Identifier for the Admin or I/O Queue
 * @cqsize:        size of the Completion Queue to be created
 * @sqsize:        size of the Submission Queue to be created
 * @cntlid:        controller ID requested
 * @hostsid:       host session identifier that is used to identify
 *                 a host to NVM subsystem session uniquely to a host
 */
struct nvme_rdma_cm_req {
	__le16		recfmt;
	__le16		qid;
	__le16		cqsize;
	__le16		sqsize;
	__le16		cntlid;
	u8		rsvd[6];
	uuid_le		hostsid;
};

/**
 * struct nvme_rdma_cm_rep - rdma connect reply
 *
 * @recfmt:        format of the RDMA Private Data
 */
struct nvme_rdma_cm_rep {
	__le16		recfmt;
};

/**
 * struct nvme_rdma_cm_rej - rdma connect reject
 *
 * @recfmt:        format of the RDMA Private Data
 * @fsts:          error status for the associated connect request
 */
struct nvme_rdma_cm_rej {
	__le16		recfmt;
	__le16		fsts;
};

#endif /* _LINUX_NVME_RDMA_H */
