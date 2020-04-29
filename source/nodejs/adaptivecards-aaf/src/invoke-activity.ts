export interface InvokeActivity {
    type: "invoke",
    name: "adaptiveCard/action",
    channelId?: string,
    localTimezone: string,
    localTimestamp: string,
    from?: {
        id: string
    },
    conversation?: {
        id: string
    },
    replyToId?: string, // Remove?
    entities?: object[],
    channelData?: object,
    serviceUrl?: string, // Remove?
    value: {
        action: {
            type: "Action.Execute",
            id?: string,
            verb: string,
            data?: object
        },
        magicCode?: string
    },
    relatesTo?: string
}

export enum ActivityInvocationTrigger {
    Automatic,
    UserInteraction,
}

export interface ActivityRequest {
    readonly activity: InvokeActivity,
    readonly trigger: ActivityInvocationTrigger,
    attemptNumber: number
}

export enum ActivityStatus {
    Success,
    Failure
}

export interface ActivityResponse {
    readonly request: ActivityRequest,
    readonly status: ActivityStatus,
    readonly content: string
}
